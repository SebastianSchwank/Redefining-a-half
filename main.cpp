#include <QCoreApplication>

#include <iostream>
#include <cstdio>
#include <ctime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //std::cout << "This is one (1) random Division with 128 Iterations starting from 0.0-1.0 \n and converges against :";
    std::cout << "These are onehundred and twentyeight (1024) random Divisions with 128 Iterations starting from 0.0-1.0 \n and converges against the mean :";
    float mean = 0.0;

    srand(time(NULL));

    for(int j = 0; j < 1024; j++){

        float upper = 1.0;
        float divisor;
        float lower = 0.0;

        for(int i = 0; i < 128; i++){
            divisor = (upper-lower)*rand()/RAND_MAX+lower;
            if(rand()%2 == 0)
                lower = divisor;
            else
                upper = divisor;
        }

    std::cout << divisor << "\n" ;
    mean += divisor;


    }

    std::cout << mean/1024.0 ;

    return a.exec();
}
