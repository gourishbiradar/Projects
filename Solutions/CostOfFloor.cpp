#include <iostream>
using namespace std;
int floor_cost(int floor_area, int tile_area, int cost_per_tile)
{
    int number_of_tile = floor_area/tile_area;
    if(floor_area%tile_area)
        number_of_tile++;
    return number_of_tile*cost_per_tile;
}
int main()
{
    int width,height,f_width,f_height,cpt;
    cout<<"Enter the floor width and height:";
    cin>>width>>height;
    cout<<"Enter the tile width and height:";
    cin>>f_width>>f_height;
    cout<<"Enter the cost per tile:";
    cin>>cpt;
    cout<<"The cost of covering a floor of area " <<(width*height)<<" with tiles of area "<<(f_width*f_height)<<" is "<<floor_cost((width*height),(f_width*f_height),cpt);
    return 0;
}