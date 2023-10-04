/*
 *  genPieces.cpp
 *  cc65 Chess
 *
 *  Created by Oliver Schmidt, January 2020.
 *  Pieces designed by Frank Gebhart, 1980s.
 *  Modified for C64 by S. Wessels, May 2020.
 *
 */

#include <fcntl.h>
#ifdef _WIN32
#include <io.h>
#else
#include <unistd.h>
#endif

#include <stdio.h>
#include <memory.h>

char pieces[]=
"                     " 
"                     " 
" ****   *****   **** " 
" *  *   *   *   *  * " 
" *  *   *   *   *  * " 
" *  *****   *****  * " 
" *                 * " 
"  *               *  " 
"   *             *   " 
"    * ********* *    " 
"    **         **    " 
"     *         *     " 
"     *         *     " 
"     *         *     " 
"     *         *     " 
"     *         *     " 
"    *           *    " 
"   *             *   " 
"   * *********** *   " 
"  *               *  " 
" ******************* " 
" ******************* " 
"                     " 
"                     " 
"                     " 
"                     " 
" ****   *****   **** " 
" ****   *****   **** " 
" ****   *****   **** " 
" ******************* " 
" ******************* " 
"  *****************  " 
"   ***************   " 
"    *************    " 
"    *           *    " 
"     ***********     " 
"     ***********     " 
"     ***********     " 
"     ***********     " 
"     ***********     " 
"    *************    " 
"   ***************   " 
"   ***************   " 
"  *               *  " 
" ******************* " 
" ******************* " 
"                     " 
"                     " 
"                     " 
"                     " 
"       *   *         " 
"      * * * *        " 
"     *    *  *       " 
"     *        *      " 
"    *          *     " 
"    *   *    * *     " 
"    *        * *     " 
"   *         ** *    " 
"  *           * *    " 
" *              *    " 
" *    ****      *    " 
"  *  *    *   * **   " 
"   **    *    ** *   " 
"        *      *  *  " 
"       *        * *  " 
"      *           ** " 
"     *             * " 
"    * ************ * " 
"    *              * " 
"    **************** " 
"                     " 
"                     " 
"                     " 
"                     " 
"       *   *         " 
"      * * * *        " 
"     ***** ***       " 
"     **********      " 
"    ************     " 
"    **** **** **     " 
"    ********* **     " 
"   **********  **    " 
"  ************ **    " 
" ****************    " 
" ****************    " 
"  ****    **** ***   " 
"   **    *****  **   " 
"        ******* ***  " 
"       ********* **  " 
"      ************** " 
"     *************** " 
"    *              * " 
"    **************** " 
"    **************** " 
"                     " 
"                     " 
"                     " 
"                     " 
"                     " 
"         ***         " 
"        *   *        " 
"       *     *       " 
"      *   *   *      " 
"     *    *    *     " 
"     * ******* *     " 
"    *     *     *    " 
"    *     *     *    " 
"    *     *     *    " 
"     *    *    *     " 
"     *         *     " 
"      *       *      " 
"       *******       " 
"       *     *       " 
"       *     *       " 
"        *****        " 
"     *         *     " 
"   ***************   " 
"  *****************  " 
"                     " 
"                     " 
"                     " 
"                     " 
"                     " 
"         ***         " 
"        *****        " 
"       *******       " 
"      **** ****      " 
"     ***** *****     " 
"     **       **     " 
"    ****** ******    " 
"    ****** ******    " 
"    ****** ******    " 
"     ***** *****     " 
"     ***********     " 
"      *********      " 
"       *     *       " 
"       *******       " 
"       *******       " 
"        *****        " 
"     ***********     " 
"   *             *   " 
"  *****************  " 
"                     " 
"                     " 
"                     " 
"                     " 
"                     " 
"         ***         " 
"        *   *        " 
"   ***  *   *  ***   " 
"  *   *  * *  *   *  " 
" *    * *   * *    * " 
" *   * *     * *   * " 
" *                 * " 
" *   *    *    *   * " 
" *   **  ***  **   * " 
"  *   *********   *  " 
"  *    *******    *  " 
"   *             *   " 
"   *             *   " 
"   * *********** *   " 
"    *           *    " 
"    *           *    " 
"    *           *    " 
"    **         **    " 
"     ***********     " 
"                     " 
"                     " 
"                     " 
"                     " 
"                     " 
"         ***         " 
"        *****        " 
"   ***  *****  ***   " 
"  *****  ***  *****  " 
" ****** ***** ****** " 
" ***** ******* ***** " 
" ******************* " 
" **** **** **** **** " 
" ****  **   **  **** " 
"  ****         ****  " 
"  *****       *****  " 
"   ***************   " 
"   ***************   " 
"   **           **   " 
"    *************    " 
"    *************    " 
"    *************    " 
"    *************    " 
"     ***********     " 
"                     " 
"                     " 
"                     " 
"                     " 
"         ***         " 
"         * *         " 
"       *** ***       " 
"       **   **       " 
"     **  * *  **     " 
"    *  * * * *  *    " 
"   *    ** **    *   " 
"  *      * *      *  " 
"  *  *  *   *  *  *  " 
" *  *    * *    *  * " 
" *  *     *     *  * " 
" *   *    *    *   * " 
"  *   *       *   *  " 
"  *    *     *    *  " 
"   *             *   " 
"   *  *********  *   " 
"    *           *    " 
"    *           *    " 
"    **         **    " 
"     ***********     " 
"                     " 
"                     " 
"                     " 
"                     " 
"         ***         " 
"         * *         " 
"       *** ***       " 
"       **   **       " 
"     **  * *  **     " 
"    **** * * ****    " 
"   ******* *******   " 
"  *******   *******  " 
"  *** ** * * ** ***  " 
" *** ****   **** *** " 
" *** ***** ***** *** " 
" **** ********* **** " 
"  **** ******* ****  " 
"  ***** ***** *****  " 
"   ***************   " 
"   **           **   " 
"    *************    " 
"    *************    " 
"    *************    " 
"     ***********     " 
"                     " 
"                     " 
"                     " 
"                     " 
"                     " 
"                     " 
"                     " 
"                     " 
"         ***         " 
"        *   *        " 
"       *     *       " 
"       *     *       " 
"       *     *       " 
"        *   *        " 
"         ***         " 
"        *   *        " 
"        *   *        " 
"       **   **       " 
"        *   *        " 
"        *   *        " 
"       *******       " 
"      *       *      " 
"     ***********     " 
"     ***********     " 
"                     " 
"                     " 
"                     " 
"                     " 
"                     " 
"                     " 
"                     " 
"                     " 
"         ***         " 
"        *****        " 
"       *******       " 
"       *******       " 
"       *******       " 
"        *****        " 
"         ***         " 
"        *****        " 
"        *****        " 
"       *******       " 
"        *****        " 
"        *****        " 
"       *******       " 
"      *       *      " 
"     ***********     " 
"     ***********     " 
"                     " 
"                     " 
;

int main(void)
{
    int i, j, k;
    unsigned int c[8] ;

    memset(c,0,sizeof(c));
    j = k = 0;
    printf("const char gfxTiles[PAWN][2][96] = \n{\n");
    for(i=0; i<sizeof(pieces); ++i)
    {
        c[j] |= (pieces[i] == '*') << (26-(i%21));
        if (!(i%21))
        {
            ++j;
            if(!(j%8))
            {
                if(!k)
                    printf("\t{\n");
                k++;
                printf("\t\t{");
                int x, y;
                for(x=0;x<4;x++)
                {
                    printf("\n\t\t\t");
                    unsigned char v;
                    for(y=0;y<8;y++)
                    {
                        v = (c[y] >> (8*(3-x))) & 0xff;
                        printf("0x%02X, ", v);
                    }
                }
                printf("\n\t\t},\n");
                if(2==k)
                {
                    printf("\t},\n");
                    k = 0;
                }
                j = 0;
                for(y=0;y<8;y++)
                {
                    c[y] = 0;
                }
            }
        }
    }
    printf("};\n");
    
    return 0;
}
