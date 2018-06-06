#ifndef SOCKETSERVIDOR_H
#define SOCKETSERVIDOR_H

#include <string>
#include <mutex>
class SocketServidor
{
public:
    SocketServidor(std::string ip, std::string puerto);
    virtual ~SocketServidor();
    bool estaConectado();
    void generarMasterSocketFD(std::string ip, std::string puerto);
    void enviarByte(char byte);
    std::string recibirString();
    void enviarString(std::string unString);
    char recibirByte();

protected:

private:
    static int masterSocketFD;
    static int masterSocketFDConectado;
    static std::mutex mutexSocketMaster;
    int socketFD;
    bool socketConectado;
    int estadoSocket;
};

#endif // SOCKETSERVIDOR_H
