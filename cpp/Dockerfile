FROM gcc

WORKDIR /usr/src/myapp
COPY . .
RUN g++ -o myapp src/main.cpp
CMD ["./myapp"]
