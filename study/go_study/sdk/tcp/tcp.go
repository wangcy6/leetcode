package main

import (
    "fmt"
    . "syscall"
)

func main() {
    var (
        clientsock int
        serveraddr SockaddrInet4
        err        error
    )

    if clientsock, err = Socket(AF_INET, SOCK_STREAM, IPPROTO_IP); err != nil {
        fmt.Println("Client Socket() called error:", err.Error())
        return
    }
    SetsockoptInt(clientsock, SOL_SOCKET, SO_REUSEADDR, 1)

    defer Shutdown(clientsock, SHUT_RDWR)
    //serveraddr.Addr = [4]byte{58, 217, 200, 15}
    serveraddr.Addr = [4]byte{111, 161, 3, 173}
    serveraddr.Port = 80

    err = Bind(clientsock, &SockaddrInet4{
        Port: 12345,
    })

    if err = Connect(clientsock, &serveraddr); err != nil {
        fmt.Println("Client Connect() called error:", err.Error())
        return
    }
}