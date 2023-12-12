# camel


## Compile

To compile the project, run ```make``` in the root directory of the project. This will create a ```camel``` shared library in the root directory of the project. It will automatically detect the platform and compile the appropriate version of the library, so in linux it will compile the ```camel.so``` library and in windows it will compile the ```camel.dll``` library. To compile the tests, first make sure to have compiled the library beforehand, then run ```make test``` in the root directory of the project. This will create a ```test``` executable in the test directory of the project. It will automatically detect the platform and compile the appropriate version of the executable, so in linux it will compile the ```test``` executable and in windows it will compile the ```test.exe``` executable. To clean the project, run ```make clean``` in the root directory of the project. This will remove the ```camel``` shared library (keep in mind, if you delete the shared library the ```test``` executable won't run). To clean the tests, run ```make clean-test``` in the root directory of the project. This will remove the ```test``` executable. To clean the project and the tests, run ```make clean-all``` in the root directory of the project. This will remove the ```camel``` shared library and the ```test``` executable.


## To-Do

- [ ] Create testing suite
- [ ] Create tests
- [ ] Create documentation
- [ ] Create examples