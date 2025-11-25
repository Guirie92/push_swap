/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillsan <guillsan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:38:22 by guillsan          #+#    #+#             */
/*   Updated: 2025/11/25 17:11:30 by guillsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Corrected a bug where negative numbers (such as rr gives a head = -1) will
 * yield incorrect values, e.g.: -1 % 5 = -1 instead of 4.
 * This version (with the negative check) handles negatives properly, as in
 * the calculator app.
 */
int	ft_mod(int a, int b)
{
	int	mod;

	mod = a % b;
	if (mod < 0)
		mod += b;
	return (mod);
}
