/*
    constTest.cpp

    testing the const and non-const versions of Top
*/

#include <tstack.h>



void menu(){
    std::cout << "____________Menu_____________\n";
    std::cout << "Select operation on stack: \n";
    std::cout << "1. Push\n2. Pop\n3. Top\n";
    std::cout << "4. Set OFC and direction.\n";
    std::cout << "5. Display\n6. Quit\n";
}

int main()
{
    fsu::Stack<char, 4> s;
    fsu::Stack<char, 4> s1(s);

//    s.Push('A');
////    std::cout << s.Size() << " " << s.Capacity() << '\n';
////    std::cout << ShowTop(s) << '\n';
////    ChangeTop(s,'a');
////    std::cout << ShowTop(s) << '\n';
//    s.Push('B');
//    s.Push('C');
//    s.Push('D');
//    std::cout << s;
//    s.SetOFC(' ');
////    s.Dump(std::cout);
//    std::cout << s;
//    s.SetDIR(-1);
//    s.Pop();
//    s.Pop();
////    s.Pop();
////    s.Pop();
//    std::cout << s;

    char option;
    char item;
    while(1){
        menu();
        while(!(std::cin >> option)){
            std::cout << "Bad input!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (option){
            case '1':
                std::cout << "Enter an item to push: ";
                while(!(std::cin >> item)){
                    std::cout << "Bad input!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                s.Push(item);
                break;
            case '2':
                s.Pop();
                break;
            case '3':
                std::cout << "Top item: " << s.Top() << "\n";
                break;
            case '4':
                std::cout << "\tPress \'o\'/\'O\' to set OFC.\n";
                std::cout << "\tPress \'<\' to set direction bottom to top\n";
                std::cout << "\tPress \'>\' to set direction top to bottom \n";
                char ofc;
                while(!(std::cin >> ofc)){
                    std::cout << "Bad input!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                switch (ofc){
                    case 'o':
                    case 'O':
                    std::cout << "Choose any ofc argument: \n";
                        std::cout << "\tkb input  -->  ofc argument      character name\n"
                                "\t--------       -----------       --------------\n"
                                "\t0                 '\\0'           null character\n"
                                "\tb                  ' '            blank\n"
                                "\tB                  ' '            blank\n"
                                "\tt                 '\\t'           tab\n"
                                "\tT                 '\\t'           tab\n"
                                "\tn                 '\\n'           newline\n"
                                "\tN                 '\\n'           newline\n";
                        while(!(std::cin >> ofc)){
                            std::cout << "Bad input!\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        if (ofc == '0') ofc = '\0';
                        else if (ofc == 'b' || ofc == 'B') ofc = ' ';
                        else if (ofc == 't' || ofc == 'T') ofc = '\t';
                        else if (ofc == 'n' || ofc == 'N') ofc = '\n';
                        else
                        {
                            std::cout << " ** bad ofc: only 0, b|B, t|T, n|N accepted\n";
                            break;
                        }
                        s.SetOFC(ofc);
                        break;
                    case '<': // SetDIR(bottom-to-top) - horizontal displays, top at right
                        s.SetDIR(+1);
                        break;
                    case '>': // SetDIR(top-to-bottom) - vertical displays, top on top
                        s.SetDIR(-1);
                        break;
                    default:
                        std::cout << "Wrong input\n";
                }
                break;
            case '5':

                std::cout << "\n" << s;
                break;
            case '6':
                std::cout << "Good bye!\n";
                return 0;
            default:
                std::cout << "Enter options from 1 to 5.\n";

        }
    }
    return 0;
}


