FROM ubuntu:16.04

RUN apt-get update && apt-get install -y build-essential \
    sudo \
    cmake \
    libboost-all-dev \
    libprotobuf-dev \
    protobuf-compiler \
    clang-3.6 \
    clang-format-3.6 \
    ninja-build \
    wget \
    git \
    unzip

# Make include directory
RUN mkdir ~/NeuralNetwork

RUN cd ~/NeuralNetwork \
    && mkdir include \
    && cd include\
    && wget https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.zip \
    && unzip eigen-3.4.0.zip \
    && mv eigen-3.4.0 eigen3 \
    && rm eigen-3.4.0.zip \
    && ls eigen3 \
    && cd .. 

COPY src /root/NeuralNetwork/src

RUN ls /root/NeuralNetwork/src/*

COPY ./CMakeLists.txt /root/NeuralNetwork/

RUN mkdir /root/NeuralNetwork/build \
    && cd /root/NeuralNetwork/build \
    && ls /root/NeuralNetwork \
    && cmake /root/NeuralNetwork \
    && make \
    && chmod 755 NeuralNetwork
WORKDIR /root/NeuralNetwork/

CMD [ "./build/NeuralNetwork" ]

