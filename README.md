# MPP: Marked Point Processes

c++ implementation of the Marked Point Process object detection in image processing.
  

## Compile

you need to build scilib first

```
cd mpp
mkdir build
cmake ..
make
```

## Library usage

Here is an example how to run a process on an image

```
#include <mpp>

```

## Command line tools

```
mpp -i your/image/file.tif -o your/output/file.csv -r your/output/image.tif -p your/parameter/file.json
```

# Docker

This repository contains a Dockerfile to run Mpp in a container. We highly recommend using a `docker-compose.yml` to run your containers. Here is an example of docker-compose file content:

```yaml
version: "3"
    services:
        mpp:
            container_name: mpp
            build:
            context: ./mpp
            dockerfile: Dockerfile
            volumes:
                - './data:/app/data/' 
```
