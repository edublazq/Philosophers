#include <pthread.h>
#include <stdio.h>

int	contador = 0;

void	*rutina(void *mutex_c)
{
	printf("Soy un hijo y estoy intentando acceder a una función\n");
	pthread_mutex_lock(mutex_c);
	for (int i = 0; i < 100; i++)
	{
		contador++;
		printf("%d\n", (int)pthread_self());
	}
	pthread_mutex_unlock(mutex_c);
	return (NULL);
}

int	main(void)
{
	pthread_t 		t1, t2;
	pthread_mutex_t	mutex_c;

	pthread_mutex_init(&mutex_c, NULL);
	pthread_create(&t1, NULL, &rutina, &mutex_c);
	pthread_create(&t2, NULL, &rutina, &mutex_c);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("%d", contador);
	pthread_mutex_destroy(&mutex_c);
}
