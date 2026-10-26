#if 0

void bubble_sort(Element *element)
{
    if (left < element->size) {
        if (element->items[element->a] > element->items[element->b])
        {
            swap(&element->items[element->a], &element->items[element->b]);
            swapped++;
        }
        
        element->b = element->b % (element->size - left) + 1;
        if (!(element->a = element->b - 1))
        {
            left++;
        }
    }
}

void insertion_sort(Element *element)
{
    (void) element;

    // TODO: insertion sort for tomorrow.
    assert(false && "Not implement yet!");
}

void selection_sort(Element *element)
{
    if (element->a < element->size - 2)
    {
        static int min = 0;


        if (element->b % (element->size - 1))
        {
            if (element->items[element->b] < element->items[min])
                min = element->b;
            
            element->b++;
        }
        else
        {
            swap(&element->items[element->a], &element->items[min]);


            if (element->a != element->b)
                min = element->a++;

            element->b = element->a + 1;
        }
    }
}
#endif
