#include "jerry.h"
#include "pellet.h"

Jerry::Jerry(int** board)
{
    //set image and size
    QPixmap Jerryimage("sources/Jerry.png");


   // QPixmap Jerryimage2("sources/Jerry.png");
    //Jerry newjerry(board);
    Jerryimage = Jerryimage.scaledToWidth(50);
    Jerryimage = Jerryimage.scaledToWidth(50);



    setPixmap(Jerryimage);


    //QPix* ne2= &Jerryimage2;


    //set positon
    row =1;
    column = 1;
    setPos(50+(50*column),50+(50*row));

    for(int i =0; i<10; i++)
        for(int j =0; j<10; j++){
            data[i][j] = board[i][j];
        }
}

void Jerry::setjerrydata(int board[10][10]){
    for(int i =0; i<10; i++)
        for(int j =0; j<10; j++){
            data[i][j] = board[i][j];
        }
}

bool Jerry:: isColide(){
    QList<QGraphicsItem*> colliding= collidingItems();

    for(int i=0;i<colliding.size();i++){

        if(typeid((*colliding[i]))== typeid(pellet)){
            scene()->removeItem(colliding[i]);
            //scene()->removeItem(this);
            QPixmap Jerryimage("sources/jerryrunning2.png");

            Jerryimage = Jerryimage.scaledToWidth(50);
            Jerryimage = Jerryimage.scaledToWidth(50);
            setPixmap(Jerryimage);
            return true;
}
        else return false;
    }
}

void Jerry:: keyPressEvent(QKeyEvent* event){
    isColide();
    if(event->key() ==Qt::Key_Up && data[row-1][column] >=0){
           row--;

       }
       else if(event->key()==Qt::Key_Down && data[row+1][column] >=0){
           row++;

       }
       else if(event->key() == Qt::Key_Right && data[row][column+1]>=0){
           column++;
if(isColide()==true) {

    QPixmap Jerryimage("sources/jerryrunningRight.png");

    Jerryimage = Jerryimage.scaledToWidth(50);
    Jerryimage = Jerryimage.scaledToWidth(50);
    setPixmap(Jerryimage);

}
else{
           //set image and size
           QPixmap Jerryimage("sources/Jerry.png");
          // QPixmap Jerryimage2("sources/Jerry.png");
           //Jerry newjerry(board);
           Jerryimage = Jerryimage.scaledToWidth(50);
           Jerryimage = Jerryimage.scaledToWidth(50);

           setPixmap(Jerryimage);
}
       }
       else if(event->key()==Qt::Key_Left && data[row][column-1]>=0){
           column--;
           if(isColide()==true) {

               QPixmap Jerryimage("sources/jerryrunning2.png");

               Jerryimage = Jerryimage.scaledToWidth(50);
               Jerryimage = Jerryimage.scaledToWidth(50);
               setPixmap(Jerryimage);

           }
           else{

           //change jerry photo:
            QPixmap JerryLeftimage("sources/Jerryleft.png");
            JerryLeftimage = JerryLeftimage.scaledToWidth(50);
            JerryLeftimage = JerryLeftimage.scaledToWidth(50);
            setPixmap(JerryLeftimage);
}
       }

    setPos(50+(50*column),50+(50*row));
}
