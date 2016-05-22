#include <stdint.h>
#include <stdio.h>
#include <algorithm>
 
typedef uint_fast8_t U8;
typedef uint_fast32_t U32;
 
static U32 Read(unsigned char** buffer) {
  unsigned char* ptr(*buffer);
  unsigned char d;
  do {
    d = *ptr++ - '0';
  } while (d > 9);
  U32 n(d);
  while ((d = *ptr - '0') <= 9) {
    n = n * 10 + d;
    ++ptr;
  }
  *buffer = ptr;
  return n;
}
 
class Leaf32 {
 public:
  static const U32 kSize = 32;
  static void InitPC();
  Leaf32();
  template<bool flip>
  U32 Operate(U32 a, U32 b);
 private:
  static U8 pc2_[];
  U32 heads_;
};
 
const U32 Leaf32::kSize;
U8 Leaf32::pc2_[static_cast<U32>(1) << 16];
 
void Leaf32::InitPC() {
  for (U32 i(0); i != (static_cast<U32>(1) << 16); ++i) {
    Leaf32::pc2_[i] = __builtin_popcount(i) * 2;
  }
}
 
Leaf32::Leaf32() : heads_(0) {
}
 
template<bool flip>
inline U32 Leaf32::Operate(U32 a, U32 b) {
  U32 mask((static_cast<U32>(2) << b) - (static_cast<U32>(1) << a));
  if (flip) heads_ ^= mask;
  union {
    uint32_t x;
    uint16_t y[2];
  } z = {heads_ & mask};
  U32 pc(pc2_[z.y[0]] + pc2_[z.y[1]]);
  return pc - (b + 1 - a);
}
 
template<U32 kArity, class T>
class Branch {
 public:
  static const U32 kSize = kArity * T::kSize;
  Branch();
  template<bool flip>
  U32 Operate(U32 a, U32 b);
 private:
  U32 flipped_;
  U32 count_;
  T heads_[kArity];
};
 
template<U32 kArity, class T>
const U32 Branch<kArity, T>::kSize;
 
template<U32 kArity, class T>
Branch<kArity, T>::Branch() : flipped_(1), count_(-kSize), heads_() {
}
 
template<U32 kArity, class T>
template<bool flip>
inline U32 Branch<kArity, T>::Operate(U32 a, U32 b) {
  if (a == 0 && b == kSize - 1) {
    if (flip) flipped_ *= -1;
    return flipped_ * count_;
  }
  U32 aq(a / T::kSize);
  U32 ar(a % T::kSize);
  U32 bq(b / T::kSize);
  U32 br(b % T::kSize);
  U32 range_count;
  if (aq == bq) {
    range_count = heads_[aq].template Operate<flip>(ar, br);
  } else {
    range_count = heads_[aq].template Operate<flip>(ar, T::kSize - 1);
    T* last(&heads_[bq]);
    for (T* t(&heads_[aq + 1]); t != last; ++t) {
      range_count += t->template Operate<flip>(0, T::kSize - 1);
    }
    range_count += last->template Operate<flip>(0, br);
  }
  if (flip) count_ += range_count * 2;
  return flipped_ * range_count;
}
 
int main() {
  Leaf32::InitPC();
  size_t length(0);
  size_t reserved(8192);
  unsigned char* input(new unsigned char[length + reserved]);
  while (true) {
    size_t count(fread(input + length, sizeof *input, reserved, stdin));
    length += count;
    if (count < reserved) break;
    reserved = length;
    unsigned char* new_input(new unsigned char[length + reserved]);
    std::copy(input, input + length, new_input);
    delete[] input;
    input = new_input;
  }
  input[length] = '\0';
  unsigned char* input_last(input);
  U32 n(Read(&input_last));
  U32 q(Read(&input_last));
  unsigned char* output(new unsigned char[q * 7]);
  unsigned char* output_last(output);
  static Branch<16, Branch<16, Branch<16, Leaf32> > > tree;
  while (q--) {
    U32 op(Read(&input_last));
    U32 a(Read(&input_last));
    U32 b(Read(&input_last));
    if (op) {
      U32 count((tree.Operate<false>(a, b) + (b + 1 - a)) / 2);
      unsigned char* first(output_last);
      do {
        *output_last++ = '0' + count % 10;
        count /= 10;
      } while (count);
      std::reverse(first, output_last);
      *output_last++ = '\n';
    } else {
      tree.Operate<true>(a, b);
    }
  }
  delete[] input;
  fwrite(output, sizeof *output, output_last - output, stdout);
  delete[] output;
}