/*
U - 0
L - 1
F - 2
R - 3
B - 4
D - 5
*/

class RubiksCube{
   public: 
        int faces[6] = {0,1,2,3,4,5};
        int pos[6][2] = {{0,2},{1,1},{2,1},{-1,1},{0,1},{0,0}};

        void flip(){
            int temp = faces[0];
            faces[0] = faces[2];
            faces[2] = faces[5];
            faces[5] = faces[4];
            faces[4] = temp;
        }

        void rotate_clockwise()
        {
            int temp = faces[1];
            faces[1] = faces[2];
            faces[2] = faces[3];
            faces[3] = faces[4];
            faces[4] = temp;
        }

        void rotate_anticlockwise()
        {
            int temp = faces[3];
            faces[1] = faces[4];
            faces[2] = faces[1];
            faces[3] = faces[2];
            faces[4] = temp;
        }

        int* get_position(int face){
            for(int i =0; i < 6; i++){
                if(faces[i] == face){
                    return this->pos[i];
                }
            }
        }
    };