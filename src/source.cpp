#include <iostream>

#include "../include/header.h"

//Распределение сущностей
void Pond::distributionOfEntities(int numberOfEntities, char entity)
{
    for (int i{}; i < numberOfEntities; ++i)
    {
        int col = uid(dre);
        int row = uid(dre);

        if (pond[row][col] == signEmpty) pond[row][col] = entity;
        else --i;
    }
}

//Вытягивание удочки
void Pond::pullFishingRod(int numberOfSector)
{
    //Закинута ли удочка за пределы пруда
    if (numberOfSector <= 0 || numberOfSector > size * size) throw ExceptionInvalidSectorNumber();

    //Определение координат крючка
    int row{ numberOfSector / size };
    int col{ numberOfSector % size };

    if (!col)
    {
        row -= 1;
        col = size - 1;
    }
    else col -= 1;

    //Поймали рыбу или сапог
    if (pond[row][col] == signFish)
    {
        pond[row][col] = ' ';
        throw ExceptionCaughtFish();
    }
    else if (pond[row][col] == signBoot)
    {
        pond[row][col] = ' ';
        throw ExceptionCaughtBoot();
    }
}

void Pond::output() const
{
    std::cout << "Pond:\n";

    for (int i{}; i < size; ++i)
    {
        for (int k{}; k < size; ++k)
            std::cout << pond[i][k] << ' ';

        std::cout << '\n';
    }
}