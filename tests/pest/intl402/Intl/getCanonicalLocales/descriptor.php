<?php

/**
 * Portions of this file are
 * Copyright (C) 2017 André Bargull. All rights reserved.
 * Used in accordance with the BSD License found in the LICENSE.Test262 file.
 */

declare(strict_types=1);

use Ecma\Intl;

// Since PHP's object model is very different from JavaScript's, we can't test
// whether the getCanonicalLocales "property" is writable, enumerable, or
// configurable, so we take an alternate approach here and test that it's a
// public static method. This ensures any polyfills or alternate implementations
// are identical.

$reflected = new ReflectionMethod(Intl::class, 'getCanonicalLocales');

it('is a static method on Ecma\\Intl')
    ->expect($reflected->isStatic())
    ->toBeTrue();

it('is a public method on Ecma\\Intl')
    ->expect($reflected->isPublic())
    ->toBeTrue();
