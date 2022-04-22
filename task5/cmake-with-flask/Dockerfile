FROM gcc:latest as build

WORKDIR /opt/techprog
ADD . /opt/techprog


RUN apt-get update
RUN apt-get -y install cmake
RUN cmake -B build
RUN cmake --build build/

FROM python:3.8-slim-buster

WORKDIR /opt/techprog
COPY --from=build /opt/techprog/bin ./bin
COPY --from=build /opt/techprog/lib ./lib
COPY --from=build /opt/techprog/app.py ./app.py

RUN pip install flask


RUN useradd --system tp2022user
USER tp2022user

CMD python3 app.py --port 8898 --host 0.0.0.0
