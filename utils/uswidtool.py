#!/usr/bin/env python3
"""
Wrap the uswid cli, ensuring the local copy
of cbor and pefile are used.
"""

import runpy
import sys

sys.path.append('python-uswid')
sys.path.append('pefile')
sys.path.append('cbor2')

runpy.run_module('uswid.cli', run_name='__main__')
