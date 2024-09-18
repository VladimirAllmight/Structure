#include <stdio.h>
#include <locale.h>

// Определяем перечисляемый тип для направления корабля
enum Direction {
    NORTH = 0, 
    WEST = 1,  
    SOUTH = 2, 
    EAST = 3   
};

// Определяем перечисляемый тип для команды
enum Command {
    BACK = 0,   
    RIGHT = 1,  
    LEFT = 2    
};

// Функция для вычисления нового направления
Direction getNewDirection(Direction currentDirection, Command command) {
    switch (command) {
    case BACK:
        return (Direction)((currentDirection + 2) % 4); 
    case RIGHT:  
        return (Direction)((currentDirection + 1) % 4); 
    case LEFT:   
        return (Direction)((currentDirection + 3) % 4); 
    default:
        return currentDirection;  // если неизвестная команда
    }
}

// Функция для вывода направления
void printDirection(Direction direction) {
    switch (direction) {
        case NORTH: printf("Север\n"); break;
        case WEST:  printf("Запад\n"); break;
        case SOUTH: printf("Юг\n");    break;
        case EAST:  printf("Восток\n"); break;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
   
    Direction currentDirection = NORTH;
    Command command = LEFT;

    char* TmpDirection;
    printf("Введите текущее направление корабля: ");
    scanf("%s", &TmpDirection);

    printf("Текущий курс: ");
    printDirection(currentDirection);
    Direction newDirection = getNewDirection(currentDirection, command);

    printf("Новый курс: ");
    printDirection(newDirection);

    return 0;
}
