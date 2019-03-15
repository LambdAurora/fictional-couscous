/*
 * Copyright © 2019 LambdAurora <aurora42lambda@gmail.com>, Shad Amethyst <shad.amethyst@gmail.com>
 *
 * This file is part of fictional_couscous.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#include <lambdacommon/system/terminal.h>

namespace term = lambdacommon::terminal;

int main(int argc, char **argv) {
    term::setup();
    return EXIT_SUCCESS;
}