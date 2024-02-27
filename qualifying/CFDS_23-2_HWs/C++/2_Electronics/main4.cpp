#include <stdio.h>
#include <stdlib.h>
#include "Electronics.h"

int main() {
  Electronics* e1 = new TV(600);
  Electronics* e2 = new Cellphone(160);
  Laptop * e3 = new Laptop(330);
  Desktop * e4 = new Desktop(400);

  Computer * laptopGPU = new Computer(50);
  Computer * GPU1 = new Computer(50);
  Computer * GPU2 = new Computer(20);
  
  e1->PrintSelf();
  e2->PrintSelf();
  e3->PrintSelf();
  e4->PrintSelf();
  

  delete e1;
  delete e2;
  delete e3;
  delete e4;

  return EXIT_SUCCESS;
}
