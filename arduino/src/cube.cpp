/*
U - 0
L - 1
F - 2
R - 3
B - 4
D - 5
*/


class Face{
    public:
    int color;
    Face(int position){
        this->color = position;
    }
};

class RubiksCube{
   public: 
        Face faces[6] = {Face(0), Face(1), Face(2), Face(3), Face(4), Face(5)};
        int pos[6][2] = {{0,2},{1,1},{2,1},{-1,1},{0,1},{0,0}};

        void flip(){
            Face temp = faces[0];
            faces[0] = faces[2];
            faces[2] = faces[5];
            faces[5] = faces[4];
            faces[4] = temp;
        }

        void rotate_clockwise()
        {
            Face temp = faces[1];
            faces[1] = faces[2];
            faces[2] = faces[3];
            faces[3] = faces[4];
            faces[4] = temp;
        }

        void rotate_anticlockwise()
        {
            Face temp = faces[3];
            faces[1] = faces[4];
            faces[2] = faces[1];
            faces[3] = faces[2];
            faces[4] = temp;
        }

        int* get_position(int face){
            for(int i =0; i < 6; i++){
                if(faces[i].color == face){
                    return this->pos[i];
                }
            }
        }
    };