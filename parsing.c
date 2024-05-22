/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:44:24 by ksainte           #+#    #+#             */
/*   Updated: 2024/05/21 13:44:31 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Flood Filling the Map

// Now that your Makefile is complete, you can move on to parsing. The main part of it is about this rule: “You have to check if there is a valid path in the map”.

// This means two things:

//     The player needs access to the exit.
//     The player, prior to exiting the map, is able to collect all collectables.

// This can be done in a single recursive function, which follows a similar pattern to the below pseudo-code:

// if (all_collectables_collected && exit_count == 1)
// 	return map_valid;
// if (on_wall)
// 	return map_invalid;
// if (on_collectable)
// 	collectables++;
// if (on_exit)
// 	exits++;
// replace_current_position_with_wall;
// if (one_of_the_four_adjacent_directions_is_possible)
// 	return map_valid;
// return map_invalid;
