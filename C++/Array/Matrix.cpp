// Matrix

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

// Given a image NXN rotate it by 90 degree
// best way is get a transpose and reverse each row
// O(N2)
void RotateImage(int matrix[][3], int N)
{
    // make a transpose of matrix
    for(int i=0;i<N; i++)
    {
        for(int j= i+1;j<N;j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // reverse each row
    for(int i=0;i<N; i++)
    {
        for(int j=0 ;j <= N/2;j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][N-j-1];
            matrix[i][j] = temp;
        }
    }
}

// print square matrix
void PrintMatrix(int matrix[][3], int N)
{
    for(int i=0;i<N; i++)
    {
        for(int j=0 ;j < N;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
    cout<<endl;
    }
}

// Set the row and column zero if any one of them is zero
void SetZeros(int matrix[][3], int R, int C)
{
    bool *Row = new bool[R-1];
    bool *Col = new bool[C-1];

    for(int i=0; i<R; i++)
        Row[i] = false;

    for(int i=0; i<C; i++)
        Col[i] = false;

    for(int i=0; i<R; i++)
    {
        for(int j=0; j< C ; j++)
        {
            if(matrix[i][j] ==0)
            {
                Row[i] = true;
                Col[j] = true;
            }
        }
    }

    for(int i=0; i<R; i++)
    {
        for(int j=0; j< C ; j++)
        {
            if((Row[i] == true) || (Col[j] == true))
            {
                matrix[i][j] = 0;
            }
        }
    }
delete[] Row;
delete[] Col;
}

// Matrix Multiplications



// Sparse Matrix multi dimentional map
class SparseMatrix {
    private:
        int MAXROW;
        int MAXCOL;
        unordered_map<int, unordered_map<int, int> > Map;
        unordered_map<int, unordered_map<int, int> > Map_x_it;
        unordered_map<int, int> Map_y_it;
    public:
        SparseMatrix(int N, int M) {
            MAXROW = N;
            MAXCOL = M;
        }

        int LookUp(int i, int j) {
            if (i >= MAXROW || j >= MAXCOL) throw;
            if (Map.find(i) != Map.end()) {
                if (Map[i].find(j) != Map[i].end()) {
                    return Map[i][j];
                }
            }
            return 0;
        }

        void Update(int i, int j, int val) {
            if (i >= MAXROW || j >= MAXCOL) throw;
            if (Map.find(i) != Map.end()) {
                if (Map[i].find(j) != Map[i].end()) {
                    if(val) Map[i][j] = val;
                    else Map[i].erase(Map[i].find(j));
                } else {
                    if (val) Map[i][j] = val;
                }
            } else {
                Map[i][j] = val;
            }
            return;
        }
};

/* ------ Not working
// Sparse Matrix using composite key map
class SparseMatrix1 {
    private:
        int MAXROW;
        int MAXCOL;
        map<pair<int, int>, int> Map;
        map<pair<int, int>, int>::iterator it;
    public:
         SparseMatrix1(int N, int M) {
            MAXROW = N;
            MAXCOL = M;
        }

        int LookUp(int i, int j) {
            if (i >= MAXROW || j >= MAXCOL) throw;
            it = Map.find(make_pair(i, j));
            if ( it != Map.end()) {
                return Map[make_pair(i, j)];
            }
            return 0;
        }

        void Update(int i, int j, int val) {
            if (i >= MAXROW || j >= MAXCOL) throw;
            it = Map.find(make_pair(i, j));
            if ( it != Map.end()) {
                if (val) {
                    Map[make_pair(i, j)] = val;
                } else {
                    Map.erase(it);
                }
            }
            return;
        }
}; */

int map[25][10];
int path(int x, int y , int MAX_ROW, int MAX_COL)
{
  if(x < MAX_ROW && y < MAX_COL) {
    if(map[x][y] != 0) {
      return map[x][y];
    } else {

      if((x == MAX_ROW -1) && (y == MAX_COL -1)) {
        map[x][y] = 1;
        return 1;
     }

      int numberOfWays = path(x+1, y, MAX_ROW, MAX_COL) + path(x, y+1, MAX_ROW, MAX_COL);
      map[x][y] = numberOfWays;
      return numberOfWays;
    }
  }
  return 0;
}

// To execute C++, please define "int main()"
int main() {
  int ROW = 25, COL = 10;

  for(int i =0; i < 2;i++)
    for(int j=0; j< 2; j++)
      map[i][j] = 0;

  int numberofways = path(0, 0, ROW, COL);

  cout<<"Number of ways: "<<numberofways<<endl;
  return 0;
}


int main()
{
//    int matrix[4][3] = {{1,2,3},{0,5,7},{0,9,10},{11,17,14}};

//    int Mat[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
 //   SetZeros(matrix,4,3);
    SparseMatrix sparse(4, 5);
    sparse.Update(2, 4, 10);
    sparse.Update(1, 1, 11);
    cout<<"VALue in matrix "<<sparse.LookUp(2, 4)<<endl;
    sparse.Update(2, 4, 0);
    cout<<"VALue in matrix "<<sparse.LookUp(2, 4)<<endl;
//  RotateImage(*Mat,4);
//  PrintMatrix(*Mat, 4);
//  MultiplyMatrix();
/*  for(int i=0; i<4; i++)
        for(int j=0; j< 4 ; j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;*/
return 0;
}