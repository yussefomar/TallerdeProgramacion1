#ifndef UTIL_LOGGER_H_
#define UTIL_LOGGER_H_

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Util_Logger
{
	public:

		// Escribe una linea dentro del archivo para logueo.
		void writeLine(string line);
		// Escribe una linea dentro del archivo para logueo de advertencias.
		void writeWarningLine(string line);
		// Escribe una linea dentro del archivo para logueo de errores.
		void writeErrorLine(string line);
		// DE momento no tiene uso.-
		void deleteLine();
		// Escribe las lineas pasadas en la lista dentro del archivo para logueo.
		void writeBlock(list<string> lineList);
		// DE momento no tiene uso.-
		void deleteBlock();
		// Genera un nuevo archivo de log y hace un resguardo del anterior si existiese.-
		void createFile(unsigned short  level);
		// DE momento no tiene uso.-
		void deleteFile();
		// Actualiza el nivel del logger.
		void updateLevel(unsigned short  newLevel);
};

#endif
