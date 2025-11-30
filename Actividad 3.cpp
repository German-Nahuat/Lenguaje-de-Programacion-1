/******************************************************************************

                          Lenguaje de Programacion 1
                         Alumno: German Nahuat Nahuat
                  Actividad 3: Aplicacion para calculo de RFC

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>

// Diccionario de palabras No permitidas
const std::vector<std::string> palabrasProhibidas = {
    "PEDO", "PUTO", "PITO", "PENE", "LOCO", "VATO"
};

// Verificar y modificar palabras prohibidas del diccionario 
std::string corregirRFC (const std::string& rfc) {
    for (const std::string& palabra : palabrasProhibidas) {
        if (rfc == palabra) {
        return rfc.substr(0,3)+ "X"; // Reemplaza la ultima paralabra por ´X´
        }
    }
    return rfc;
}
// Funcion para obtener la primera vocal de una cadena
char obtenerPrimeraVocalInterna(const std::string& str) {
    for (size_t i = 1; i < str.length(); ++i) {
        char c = str[i];
        if ( c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return c;
    }
    return 'X'; // Si no encuentra vocal interna, se usa una X 
}

// Funcion principal para calcular rfc del empleado
std::string calcularRFC(const std::string& Nombre, const std::string& ApellidoPaterno, 
const std::string& ApellidoMaterno, const std::string& fechaNacimiento) {
   
    // Se declara la variable donde guardaremos el RFC 
    std::string rfc;
    
    // Se obtiene la letra inicial y la primera vocal del apellido Apellido Paterno
    char letraInicial = ApellidoPaterno[0];
    char PrimeraVocalInterna = obtenerPrimeraVocalInterna(ApellidoPaterno);
    
    // Se obtiene la inicial del apellido materno o se usa una "X" si existe
    char inicialApellidoMaterno = (!ApellidoMaterno.empty()) ? ApellidoMaterno[0] : 'X';
    
    // Se obtiene la inicial del primer Nombre
    char inicialNombre = Nombre [0];
    
    // Se obtiene los ultimos digitos del año de fechaNacimiento
    std::string anio = fechaNacimiento.substr (2, 2);
    
    // Se obtiene el mes y dia de nacimiento 
    std::string mes = fechaNacimiento.substr(5, 2);
    std::string dia = fechaNacimiento.substr(8, 2);
    
    // Se construye el RFC sumando el texto de la informacion proporcionada
    rfc = letraInicial;
    rfc += PrimeraVocalInterna;
    rfc += inicialApellidoMaterno;
    rfc += inicialNombre;
    
    // Aqui se ejecuta la comparacion de malas palabras en el diccionario y se sustituye con una X
    rfc = corregirRFC(rfc);
    
    // Realizar la correccion y se continua el rfc 
    rfc += anio;
    rfc += mes;
    rfc += dia;
    
    return rfc;
}
int main() {
    // Escribe en consola los pasos a seguir y espera los datos en mayuscula
    std::string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;
    std::cout << "Introduce tu nombre";
    std::getline(std::cin, nombre);
    std::cout<< "introduce tu apeliido paterno";
    std::getline(std::cin, apellidoPaterno);
    std::cout << "Introduce tu apellido materno (Si no cuenta con apellido materno, presionas ENTER): ";
    std::getline(std::cin, apellidoMaterno);
    std::cout << "Introduce la fecha de nacimiento en el siguiente formato (YYYY-MM-DD): ";
    std::getline(std::cin, fechaNacimiento);
    std::string rfc = calcularRFC(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento);
    std::cout << "RFC: " << rfc << std::endl;
    
    return 0;
}