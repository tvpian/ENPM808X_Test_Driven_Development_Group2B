# ENPM808X: Test Driven Development Exercise (Group 2)


## Part - 1:

**Driver:** Tharun V. Puthanveettil (tvpian@umd.edu)

**Navigator:** Jay Prajapati (jayp@umd.edu)

## Part 2:

**Driver:** Joshua Gomes (jgomes14@umd.edu) 

**Navigator:** Venkata sai ram polina (sairamp@umd.edu)


# Instructions to the run the code

Go to the cloned directory,
```sh
cd {path to the directory/test_driven_development}
```

Now we need to generate the build files,
```sh
mkdir build && cd build
```
```sh
cmake ..
```
```sh
make
```
Run the tests,
```sh
./test/cpp-test
```
Try out the PID Controller,
```sh
./app/shell-app
```
Now, to generate the coverage report,
```sh
sudo apt-get install lcov
```
```sh
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
```
```sh
make
```
```sh
make code_coverage
```
And you will get the coverage report in /build/coverage/index.html
