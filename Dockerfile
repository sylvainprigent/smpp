FROM ubuntu:18.04

WORKDIR /app

COPY . /app

RUN ./install_ubuntu.sh

RUN apt update && \
    apt upgrade && \
    apt -y install cmake && \
    apt -y install g++ && \
	mkdir build && \
	cd build && \
	cmake .. && \
	make && \

CMD ["bash"]
