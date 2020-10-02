FROM gcc

COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN g++ -o myapp src/main.cpp
CMD ["./myapp"]
