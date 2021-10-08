# multi-client-chat

A simple chat server that can accept multiple clients at a time. Implemented using the [Windows Sockets 2](https://docs.microsoft.com/en-us/windows/win32/winsock/windows-sockets-start-page-2) library, with one thread, using the select() function.  
Uses a class derived from my [tcp-listener](https://github.com/molnar-david/tcp-listener/) class.

## How to use:
0. If you don't have PuTTY or similar software, you can download PuTTY from [here](https://www.chiark.greenend.org.uk/~sgtatham/putty/), or use my TCP client [here](https://github.com/molnar-david/tcp-client)
1. Compile and run using Visual Studio (I used Visual Studio Community 2019)
2. In PuTTY, set Connection type to Raw, then connect to the server's IP address - or 127.0.0.1 (localhost) if it's running on the same network -, through the specified port (54000 by default)
3. Repeat step 2. as many times as you'd like
4. Start sending messages through clients to start chatting
5. You can close down the server anytime you want by sending the '\quit' command. This will disconnect all clients

*Made with the help of the [Networking in C++](https://www.youtube.com/playlist?list=PLZo2FfoMkJeEogzRXEJeTb3xpA2RAzwCZ) YouTube series by [Sloan Kelly](https://www.youtube.com/c/sloankelly)*  
*The tutorial series didn't include a lot of error checking, so most of it I had to look up and write myself*
