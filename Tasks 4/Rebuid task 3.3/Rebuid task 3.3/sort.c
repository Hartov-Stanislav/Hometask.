void qSort(int* array, int firstElement, int lastElement)
{
	if (firstElement >= lastElement)
	{
		return;
	}
	int i = firstElement;
	int j = lastElement;
	// Выбор "Рандомного" элемента из середины массива
	int middleElementInArray = array[(i + j) / 2];
	// Поделилим массив на две части так, что каждый элемент массива из первой части меньше любого элемента из второй
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
	// Аналогия для двух получившихся частей исходного массива и так делее
	qSort(array, firstElement, j);
	qSort(array, i, lastElement);
}
