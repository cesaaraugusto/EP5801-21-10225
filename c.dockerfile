FROM ubuntu:latest

ENV C_PATH=/c

# Make Development Folder #
RUN mkdir -p ${C_PATH}

# Make build folder #
RUN mkdir -p ${C_PATH}/build

# Make Apps Folder #
RUN mkdir -p ${C_PATH}/apps

#####################################################################
#                       Upgrade of base packages                    #
#####################################################################
# Update links for dependencies #
RUN apt update

# Install all ubuntu updates #
RUN apt full-upgrade -y

#####################################################################
#                   Instalation of dependencies                     #
#####################################################################
# Install builld essential tools like gcc, g++, make etc #
RUN apt install build-essential gdb nasm curl wget git gnupg -y

# Remove apt lists to reduce image size #
RUN rm -rf /var/lib/apt/lists/*

#####################################################################
#           Command to connect to docker instance for debugging     #
#####################################################################
# Set the working directory to the build folder #
WORKDIR ${C_PATH}