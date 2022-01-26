/// qustion link -> https://practice.geeksforgeeks.org/problems/circular-tour/1
/*
Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
Explanation: There are 4 petrol pumps with
amount of petrol and distance to next
petrol pump value pairs as {4, 6}, {6, 5},
{7, 3} and {4, 5}. The first point from
where truck can make a circular tour is
2nd petrol pump. Output in this case is 1
(index of 2nd petrol pump).
*/
     int tour(petrolPump p[],int n)
    {
        int start = 0;
        int requirdFuel = 0;
        int extraFuel = 0;
        queue<int>pt;
        queue<int>d;
        for(int i=0; i<n; i++){
            pt.push(p[i].petrol);
            d.push(p[i].distance);
        }
        for(int i=0; i<n; i++){
            extraFuel += (pt.front() - d.front());
            pt.pop();
            d.pop();
            if(extraFuel<0){
                start = i+1;
                requirdFuel += extraFuel;
                extraFuel = 0;
            }
        }
        if(requirdFuel+extraFuel >= 0) return start;
        return -1;
       //Your code here
    }
