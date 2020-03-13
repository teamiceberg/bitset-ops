#include <main.h>

using namespace std;

int main()
{
    unsigned long bsInt;
    bsInt = get_input();
    bitset<N> bs = bsInt;
    //bitset<N>* pbs = &bs;
    /*cout << "bitset.size:" << bs.size() << " bits." << endl;
    cout << "sizeof(bitset<N>):" << sizeof(bs) << " bytes." << endl;
    cout << "sizeof(bitset<N>*):" << sizeof(pbs) << " bytes." << endl;*/
    cout << "Decimal equivalent of bitset:" << bs.to_ulong() << endl;
    cout << "Binary equivalent of bitset: " << bs << endl;

    const unsigned char * bytes = print_mem_layout(&bs, bs.size() >> 3);
    //check: little endian = true: if first bit is LSB
    //get LSB
    bitset<8> lsbyte {};
    for (size_t i = 0; i < 8; i++) {
        lsbyte[i] = bs[i];
    }
    //get the lowest address byte
    bitset<8> firstbyte = {bytes[0]};

    OrdType end_type;
    lsbyte == firstbyte ?  end_type = OrdType::little : end_type = OrdType::big ;
    cout << showbase << "Least Significant Byte: " << setbase(16) << lsbyte.to_ulong() << endl;
    cout << showbase << "Lowest Address Byte in Memory: " << setbase(16) << firstbyte.to_ulong() << endl;
    switch(end_type) {
    case OrdType::little:
        cout << "your system is LITTLE endian!" << endl;
        break;
    case OrdType::big:
        cout << "your system is BIG endian!" << endl;
        break;
    default:
        cout << "your system is MIXED endian!" << endl;
    }

    return 0;
}

const unsigned char * print_mem_layout(const void *object, size_t size)
{
  const unsigned char * const bytes = static_cast<const unsigned char *>(object);
  size_t i;

  printf("memory layout of bytes: [ ");
  for(i = 0; i < size; i++)
  {
    printf("%02x ", bytes[i]);
  }
  printf("]\n");

  return bytes;
}

unsigned long get_input() {
    unsigned long myNumber = 0;
    string input = "";
     while (true) {
       cout << "Please enter an integer or a hex (must have 0x or 0X before hex number): ";
       getline(cin, input);
       stringstream intStream;
       string hexflag = input.substr(0,2);
       transform(hexflag.begin(), hexflag.end(), hexflag.begin(), ::tolower);
       if (hexflag == "0x") intStream << hex << input.substr(2);
       else intStream << input;
       //cout << "input number is: " << intStream.str()<< endl;
       // Convert string to long int safely.
       if (intStream >> myNumber) break;
       cout << "Invalid integer or hex. Try again." << endl;
     }
     return myNumber;
}
