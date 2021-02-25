#include <iostream>
#include "../include/vigenere_functions.h"

int main(void)
{
    std::string message, keyword;
    int op;

    std::string temp_key;
    bool ciphered_status = false;

    while (1)
    {
        std::cout << "\n\n--MENÚ PARA EL CIFRADO DE VIGENERE--\n\n";
        std::cout << "\t1) Introducir mensaje\n";
        std::cout << "\t2) Encriptar mensaje\n";
        std::cout << "\t3) Desencriptar mensaje\n";
        std::cout << "\t4) Mostrar mensaje en estado actual\n";
        std::cout << "\t0) Salir del programa\n";
        std::cout << "Introducir opción: ";
        std::cin >> op;
        std::cout << "\n\n";

        if (op == 0)
        {
            break;
        }

        switch (op)
        {
        case 1:
            std::cout << "Mensaje: ";
            std::cin.ignore();
            std::getline(std::cin, message, '\n');
            std::cout << "\n\n\t mensaje introducido: " << message << "\n";

            break;
        case 2:
            if (message.empty())
            {
                std::cout << "--- No hay mensaje ---\n\n";
            }
            else
            {
                if (ciphered_status == false)
                {
                    std::cout << "Itroduzca una palabra clave: ";
                    std::cin >> keyword;
                    std::cout << "\n\n\t palabra clave introducida: " << keyword << "\n";

                    message = join(v_cipher(v_split(compact(message), keyword), keyword));
                    ciphered_status = true;
                }
                else
                {
                    std::cout << "\n\n\t mensaje ya cifrado \n";
                }
            }
            break;
        case 3:
            if (message.empty())
            {
                std::cout << "--- No hay mensaje ---\n\n";
            }
            else
            {
                if (ciphered_status == true)
                {
                    std::cout << "Itroduzca la palabra clave: ";
                    std::cin >> temp_key;
                    if (temp_key != keyword)
                    {
                        std::cout << "\n\nPalabra clave equivocada - saliendo de la opción";
                    }
                    else
                    {
                        ciphered_status = false;
                        message = decipher(message, keyword);
                    }
                }
                else
                {
                    std::cout << "\n\n\t mensaje ya descifrado \n";
                }
            }

            break;
        case 4:
            if (message.empty())
            {
                std::cout << "--- No hay mensaje ---\n\n";
            }
            else
            {
                std::cout << "Mensaje en el estado actual: " << message << " \n";
            }
            break;
        default:
            std::cout << "Opción no contemplada para el número " << op
                      << " vuelva a intentarlo\n";
            break;
        }

        std::cout << "\n\t\tPulse enter para continuar...";
        getchar();
        getchar();
        system("clear");
    }

    return 0;
}

/* INSTRUCCIÖN PARA COMPROBACIÓN DEL CONTENIDO DEL TEXTO -> REGEXP */