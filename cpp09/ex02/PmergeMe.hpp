#include <deque>
#include <iostream>
#include <vector>
#include <cstdlib>

class PmergeMe
{
	public:
		template <class T>
		void sorting(T &c)
		{
			MergeInsertSort(c, 0, c.size() - 1);
		}
	private:
		template <class T>
		void MergeInsertSort(T &c, int start, int end)
		{
			if (start < end)
			{
				if (end - start < 10)
					Insertsort(c, start, end);
				else{
					int mil = start + (end - start) /2;
					MergeInsertSort(c, start, mil);
					MergeInsertSort(c, mil+1, end);
					merge(c, start, mil, end);
				}
			}
		}

		template <class T>
		void Insertsort(T &c, int start, int end)
		{
			for(int i = start + 1; i <= end; ++i)
			{
				int tmp = c[i];
				int j = i - 1;
				for (; j >= start && c[j] > tmp ; --j)
					c[j + 1] = c[j];
				c[j + 1] = tmp;
			}
		}

		template <class T>
		void	merge(T &c, int start, int mil, int end)
		{
			int len1 = mil - start + 1;
			int len2 = end - mil;

			T un(len1), deux(len2);

			for (int i = 0; i <len1; i++)
				un[i] = c[start + i];
			for (int j = 0; j <len2; j++)
				deux[j] = c[mil + 1 + j];
			
			int i = 0, j = 0, k = start;

			while (i < len1 && j < len2)
			{
				if (un[i] <= deux[j])
				{
					c[k] = un[i];
					k++;i++;
				}
				else
				{
					c[k] = deux[j];
					k++;j++;
				}
			}

			while (i < len1)
			{
				c[k] = un[i];
				k++;i++;
			}

			while (j < len2)
			{
				c[k] = deux[j];
				k++;j++;
			}
		}
};