/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:37:31 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/30 18:06:26 by romainjober      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
#define COLORS_H

// ANSI escape code for text color
#define RESET       "\033[0m"      // Reset all attributes to default
#define BLACK       "\033[30m"     // Black text
#define RED         "\033[31m"     // Red text
#define GREEN       "\033[32m"     // Green text
#define YELLOW      "\033[33m"     // Yellow text
#define BLUE        "\033[34m"     // Blue text
#define MAGENTA     "\033[35m"     // Magenta text
#define CYAN        "\033[36m"     // Cyan text
#define WHITE       "\033[37m"     // White text

// ANSI escape code for background color
#define BG_BLACK    "\033[40m"     // Black background
#define BG_RED      "\033[41m"     // Red background
#define BG_GREEN    "\033[42m"     // Green background
#define BG_YELLOW   "\033[43m"     // Yellow background
#define BG_BLUE     "\033[44m"     // Blue background
#define BG_MAGENTA  "\033[45m"     // Magenta background
#define BG_CYAN     "\033[46m"     // Cyan background
#define BG_WHITE    "\033[47m"     // White background

#endif // COLORS_H
