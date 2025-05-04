class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circle = 0;
        int square = 0;

        for(int choice : students) {
            if(choice == 0) {
                circle++;
            }
            else {
                square++;
            }
        }

        for(int sandwich : sandwiches) {
            if(sandwich == 0 && circle == 0) {
                return square;
            }
            if(sandwich == 1 && square == 0) {
                return circle;
            }

            if(sandwich == 0) {
                circle--;
            }
            else {
                square--;
            }
        }


        return 0;
    }
};