FROM debian:testing

# Atualiza os pacotes e instala as ferramentas necessárias
RUN apt-get -y update && apt-get -y install build-essential make gcc gdb flex bison valgrind

# Adiciona um novo usuário não-root
RUN useradd -s /bin/bash --create-home user

# Copia os arquivos do projeto para o diretório de trabalho
COPY . /home/user

# Muda as permissões para o usuário não-root
RUN chown -R user:user /home/user

# Muda para o usuário não-root
USER user

# Define o diretório de trabalho
WORKDIR /home/user

# Executa o comando make por padrão
CMD ["make"]
