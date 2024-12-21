#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#define NOP "nop"       // No operation

// Arithmetic operations
#define ADD "add"       // add r1, r2 => r3 // r3 = r1 + r2
#define SUB "sub"       // sub r1, r2 => r3 // r3 = r1 - r2
#define MULT "mult"     // mult r1, r2 => r3 // r3 = r1 * r2
#define DIV "div"       // div r1, r2 => r3 // r3 = r1 / r2
#define ADDI "addI"     // addI r1, c2 => r3 // r3 = r1 + c2
#define SUBI "subI"     // subI r1, c2 => r3 // r3 = r1 - c2
#define RSUBI "rsubI"   // rsubI r1, c2 => r3 // r3 = c2 - r1
#define MULTI "multI"   // multI r1, c2 => r3 // r3 = r1 * c2
#define DIVI "divI"     // divI r1, c2 => r3 // r3 = r1 / c2
#define RDIVI "rdivI"   // rdivI r1, c2 => r3 // r3 = c2 / r1

// Shift operations
#define LSHIFT "lshift"     // lshift r1, r2 => r3 // r3 = r1 << r2
#define LSHIFTI "lshiftI"   // lshiftI r1, c2 => r3 // r3 = r1 << c2
#define RSHIFT "rshift"     // rshift r1, r2 => r3 // r3 = r1 >> r2
#define RSHIFTI "rshiftI"   // rshiftI r1, c2 => r3 // r3 = r1 >> c2

// Memory operations
#define LOADI "loadI"       // loadI c1 => r2 // r2 = c1
#define LOAD "load"         // load r1 => r2 // r2 = Memoria(r1)
#define LOADAI "loadAI"     // loadAI r1, c2 => r3 // r3 = Memoria(r1 + c2)
#define LOADA0 "loadA0"     // loadA0 r1, r2 => r3 // r3 = Memoria(r1 + r2)
#define CLOAD "cload"       // cload r1 => r2 // caractere load
#define CLOADAI "cloadAI"   // cloadAI r1, c2 => r3 // caractere loadAI
#define CLOADA0 "cloadA0"   // cloadA0 r1, r2 => r3 // caractere loadA0

// Stored operations
#define STORE "store"       // store r1 => r2 // Memoria(r2) = r1
#define STOREAI "storeAI"   // storeAI r1 => r2, c3 // Memoria(r2 + c3) = r1
#define STOREAO "storeAO"   // storeAO r1 => r2, r3 // Memoria(r2 + r3) = r1
#define CSTORE "cstore"     // cstore r1 => r2 // caractere store
#define CSTOREAI "cstoreAI" // cstoreAI r1 => r2, c3 // caractere storeAI
#define CSTOREAO "cstoreAO" // cstoreAO r1 => r2, r3 // caractere storeAO

// Register copy operations
#define I2I "i2i"   // i2i r1 => r2 // r2 = r1 para inteiros
#define C2C "c2c"   // c2c r1 => r2 // r2 = r1 para caracteres
#define C2I "c2i"   // c2i r1 => r2 // converte um caractere para um inteiro
#define I2C "i2c"   // i2c r1 => r2 // converte um inteiro para caractere

// Control flow operations
#define CMP_LT "cmp_LT" // cmp_LT r1, r2 => r3 // r3 = true se r1 < r2, senão r3 = false
#define CMP_LE "cmp_LE" // cmp_LE r1, r2 => r3 // r3 = true se r1 <= r2, senão r3 = false
#define CMP_EQ "cmp_EQ" // cmp_EQ r1, r2 => r3 // r3 = true se r1 = r2, senão r3 = false
#define CMP_GE "cmp_GE" // cmp_GE r1, r2 => r3 // r3 = true se r1 >= r2, senão r3 = false
#define CMP_GT "cmp_GT" // cmp_GT r1, r2 => r3 // r3 = true se r1 > r2, senão r3 = false
#define CMP_NE "cmp_NE" // cmp_NE r1, r2 => r3 // r3 = true se r1 != r2, senão r3 = false
#define CBR "cbr"       // cbr r1 => l2, l3 // PC = endereço(l2) se r1 = true, senão PC = endereço(l3)

// Jump operations
#define JUMPI "jumpI"   // jumpI => l1 // PC = endereço(l1)
#define JUMP "jump"     // jump => r1 // PC = r1

// Logical operations
#define AND "and"       // and r1, r2 => r3 // r3 = r1 && r2
#define ANDI "andI"     // andI r1, c2 => r3 // r3 = r1 && c2
#define OR "or"         // or r1, r2 => r3 // r3 = r1 || r2
#define ORI "orI"       // orI r1, c2 => r3 // r3 = r1 || c2
#define XOR "xor"       // xor r1, r2 => r3 // r3 = r1 xor r2
#define XORI "xorI"     // xorI r1, c2 => r3 // r3 = r1 xor c2

// Registrars
// O registrador rfp é reservado como um ponteiro para a base do registro de ativação atual (o registro do
// topo da pilha).
// 4. O registrador rsp é reservado como um ponteiro para o topo da pilha.
// 5. O registrador rbss é reservado para apontar para a base do segmento de dados do programa.
// 6. O registrador rpc é reservado para manter o contador do programa (program counter).

#define RFP "rfp"   // Frame pointer
#define RSP "rsp"   // Stack pointer
#define RBSS "rbss" // Base pointer
#define RPC "rpc"   // Program counter

#endif
