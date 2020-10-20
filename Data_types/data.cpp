
// Размер памяти для основных типов данных в системе.
#include <iostream>

int main()
{
	bool VarBool = true;
	char VarChar = 'a';
	unsigned char VarUnChar = 'A';
	wchar_t VarWchar = L'F';	// UNICODE
	int varInt = 3;
    unsigned int VarUnInt = 2;
    short VarShort = 4;
    unsigned short VarUnShort = 5;
    float VarFloat = 1.2f;
    double VarDouble = 3.3;
    long VarLong = 6;
    unsigned long VarUnLong = 7;
    long long VarLongLong= 8;
    
    std::cout.setf(std::ios::boolalpha); //  перевод логического 0 и 1 в true/false
    std::cout << "bool = " << VarBool << " - " << sizeof(VarBool) << " bytes!" << std::endl;
    std::cout << "char = " << VarChar << " - " << sizeof(VarChar) << " bytes!" << std::endl;
    std::cout << "unsigned char = " << VarUnChar << " - " << sizeof(VarUnChar) << " bytes!" << std::endl;
    std::cout << "wchar_t = " << VarWchar << " (L'F')" << " - " << sizeof(VarWchar) << " bytes!" << std::endl;
    std::cout << "int = " << varInt << " - " << sizeof(varInt) << " bytes!" << std::endl;
    std::cout << "unsigned int = " << VarUnInt << " - " << sizeof(VarUnInt) << " bytes!" << std::endl;
    std::cout << "short = " << VarShort << " - " << sizeof(VarShort) << " bytes!" << std::endl;
    std::cout << "unsigned short = " << VarUnShort << " - " << sizeof(VarUnShort) << " bytes!" << std::endl;
    std::cout << "float = " << VarFloat << " - " << sizeof(VarFloat) << " bytes!" << std::endl;
    std::cout << "double = " << VarDouble << " - " << sizeof(VarDouble) << " bytes!" << std::endl;
    std::cout << "long = " << VarLong << " - " << sizeof(VarLong) << " bytes!" << std::endl;
    std::cout << "unsigned long = " << VarUnLong << " - " << sizeof(VarUnLong) << " bytes!" << std::endl;
    std::cout << "long long = " << VarLongLong << " - " << sizeof(VarLongLong) << " bytes!" << std::endl;

}
