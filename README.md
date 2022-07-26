# VTC_control_panel

This is a Qt GUI to read the data of a time tracking cube <!-- TODO: Hier link zum Cube Projekt einfügen --> and send it to
a [Vertec XML endpoint](https://www.vertec.com/de/kb/vertec-xml-schnittstelle/).

## Project Structure

Directory | Content
----------|---------
assets    | ressource files, which are not directly part of the source code
libs      | dependencies
src       | source code
src/io    | source code related to all io operations (read config files, serial communication with the cube, Vertec XML endpoint)
src/model | structs which depict this applications data model
src/state | singleton classes which manage the global state of this application
src/widgets | QtWidget classes (GUI)
