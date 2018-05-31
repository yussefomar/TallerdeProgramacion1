#ifndef SOCKETSERVIDOR_H
#define SOCKETSERVIDOR_H

#include <string>
class SocketServidor
{
public:
    SocketServidor(std::string ip, std::string puerto);
    virtual ~SocketServidor();
    bool estaConectado();
    void generarMasterSocketFD(std::string ip, std::string puerto);
    void enviarByte(char byte);
    char recibirByte();

protected:

private:
    static int masterSocketFD;
    static int masterSocketFDConectado;
    int socketFD;
    bool socketConectado;
};

#endif // SOCKETSERVIDOR_H
