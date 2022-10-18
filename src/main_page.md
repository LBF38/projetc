@mainpage
@tableofcontents

# My C-lang project documentation

## Introduction

The C project consists in loading data into a list using two methods.

## Method 1

It is a simple list. We compare the cells made from lines and then insert the cell in the right place.

## Method 2

It is an optimized list using an index. We compare the cells made from lines with an index and then insert the cell in the right index_list.

## Results

We compare the execution time of both methods using small, medium and large files.

The results are that method 2 is quicker than method 1.

# Installation

How to install and use the program.

## Step 1 : Download the archive

Firstly, download the archive containing every source files.

## Step 2 : Open the archive in a folder

Then, open the archive in a given folder on your computer.

## Step 3 : Open a terminal

Use the terminal (under Linux or any OS) and go to the folder containing the source code.

For example, you can be in `~/projetc $`

## Step 4 : Launch the app

From here, you can launch the app by using `./bin/annuaire`
If you don't add any arguments, like the file, it will tell you how to use the program.

Examples of usage :

```bash
./bin/annuaire data/small.txt
./bin/annuaire data/small.txt --display
```

## Step 5 : Enjoy

Enjoy the program and compare the execution time of methods.

Please consider using `./bin/annuaire` without any arguments to see complete usage and possible options.
