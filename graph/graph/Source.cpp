#include "Header.h"

Graph CreateGraphFromFile(string f)
{
	Graph gr;
	fstream F;
	F.open(f);
	if (!F)
	{
		cout << "Can't open file." << endl;
		return gr;
	}
	else
	{
		char s;
		F >> s;
		while (!F.eof())
		{

			for (int i = 0; i < 5; i++) // hàng
			{
				//cout << line << endl;

					for (int j = 0; j < 5; j++) // cột
					{
						F >> gr.adjacency_matrix[i][j];
						cout << gr.adjacency_matrix[i][j] << " ";
					}
					cout << endl;
			}
		}
		F.close();
	}
	return gr;
}