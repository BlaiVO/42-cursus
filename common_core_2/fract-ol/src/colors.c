/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:27:09 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/05 15:37:02 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	get_color(int n)
{
	if (n == 0)
		return (0x23071E);
	if (n == 1)
		return (0x370617);
	if (n == 2)
		return (0x6A040F);
	if (n == 3)
		return (0x9D0208);
	if (n == 4)
		return (0xD00000);
	if (n == 5)
		return (0xDC2F02);
	if (n == 6)
		return (0xE85D04);
	if (n == 7)
		return (0xF48C06);
	if (n == 8)
		return (0xFAA307);
	return (0xFFBA08);
}
