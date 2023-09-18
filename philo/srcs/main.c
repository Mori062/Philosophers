/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:36:17 by morishitash       #+#    #+#             */
/*   Updated: 2023/09/18 11:22:21 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdbool.h>

typedef struct s_mut
{
	pthread_mutex_t	*mutex;
	int	*cnt;
}	t_mut;

void *f(void *p)
{
	t_mut *t;
	t = p;

	for (int i = 0; i < 10000; ++i)
	{
        // lock ~ unlock の中の処理を動かせるのは1人だけ。lock()で待機する。
		pthread_mutex_lock(t->mutex);
		++*t->cnt;
		pthread_mutex_unlock(t->mutex);
	}
	return (NULL);
}

int main(int argc char** argv)
{
	if (argc != 5 && argc != 6)
		return (0);
	printf("I'm philo.\n");
	int cnt = 0;
	pthread_t thread1;
	pthread_t thread2;

	// 歩行者信号の設置 initで、最初unlock状態がセットされる。単純なboolではなさそう。
	pthread_mutex_t mutex;
	if (pthread_mutex_init(&mutex, NULL) != 0)
		return (1);
    // pthreadに、 cnt と mutex を渡したいので構造体にいれる。
	t_mut t;
	t.mutex = &mutex;
	t.cnt = &cnt;

	// 関数を勝手に走らせる。並列処理。
	if (pthread_create(&thread1, NULL, &f, &t) != 0)
		return (1);
	if (pthread_create(&thread1, NULL, &f, &t) != 0)
		return (1);

	// 終了するまで待機。createとセット
	if (pthread_join(thread1, NULL) != 0)
		return (1);
	if (pthread_join(thread2, NULL) != 0)
		return (1);
	if (printf("*t.cnt: %d\n", *t.cnt) < 0)
		return (1);
}
