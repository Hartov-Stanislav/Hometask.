void qSort(int* array, int firstElement, int lastElement)
{
	if (firstElement >= lastElement)
	{
		return;
	}
	int i = firstElement;
	int j = lastElement;
	// ����� "����������" �������� �� �������� �������
	int middleElementInArray = array[(i + j) / 2];
	// ��������� ������ �� ��� ����� ���, ��� ������ ������� ������� �� ������ ����� ������ ������ �������� �� ������
	do
	{
		while (array[i] < middleElementInArray)
		{
			i++;
		}
		while (array[j] > middleElementInArray)
		{
			j--;
		}
		if (i <= j)
		{
			int tempForSwap = array[i];
			array[i] = array[j];
			array[j] = tempForSwap;
			i++;
			j--;
		}
	} while (i <= j);
	// �������� ��� ���� ������������ ������ ��������� ������� � ��� �����
	qSort(array, firstElement, j);
	qSort(array, i, lastElement);
}
