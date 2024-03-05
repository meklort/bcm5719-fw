////////////////////////////////////////////////////////////////////////////////
///
/// @file       .jenkins.groovy
///
/// @project
///
/// @brief      Main Jenkins configuration
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2019, Evan Lojewski
/// @cond
///
/// All rights reserved.
///
/// Redistribution and use in source and binary forms, with or without
/// modification, are permitted provided that the following conditions are met:
/// 1. Redistributions of source code must retain the above copyright notice,
/// this list of conditions and the following disclaimer.
/// 2. Redistributions in binary form must reproduce the above copyright notice,
/// this list of conditions and the following disclaimer in the documentation
/// and/or other materials provided with the distribution.
/// 3. Neither the name of the copyright holder nor the
/// names of its contributors may be used to endorse or promote products
/// derived from this software without specific prior written permission.
///
////////////////////////////////////////////////////////////////////////////////
///
/// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
/// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
/// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
/// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
/// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
/// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
/// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
/// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
/// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
/// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
/// POSSIBILITY OF SUCH DAMAGE.
/// @endcond
////////////////////////////////////////////////////////////////////////////////

def do_build(nodeName, archive = false, archiveCab = false, analyze = true, testArchive = false)
{
    node(nodeName)
    {
        cleanWs()

        stage(nodeName + ' checkout')
        {
            checkout scm

            def gitSubject = sh (
                script: 'git show -s --format=%s',
                returnStdout: true,
            ).trim()
            currentBuild.description = gitSubject
        }

        stage(nodeName + ' build')
        {
            if (analyze)
            {
                sh './build.sh'
            }
            else
            {
                sh './build.sh -DDISABLE_CLANG_ANALYZER=True'
            }
        }

        if (archive)
        {
            stage(nodeName + ' archive')
            {
                dir('build')
                {
                    archiveArtifacts artifacts: '*.zip', fingerprint: true
                    archiveArtifacts artifacts: '*.tar.gz', fingerprint: true
                }

                if (archiveCab)
                {
                    dir('build/fwupd')
                    {
                        archiveArtifacts artifacts: '*.cab', fingerprint: true
                    }
                }
            }
        }

        if (testArchive)
        {
            cleanWs()

            stage(nodeName + ' build-release')
            {
                copyArtifacts filter: '*Source.tar.gz', fingerprintArtifacts: true, projectName: JOB_NAME, selector: specific(currentBuild.id)
                sh '''
                    tar -xvf *Source.tar.gz
                    cd *Source
                    ./build.sh -DDISABLE_CLANG_ANALYZER=True
                    '''

                // Check resulting .cab files match
                copyArtifacts filter: '*.cab', fingerprintArtifacts: true, projectName: JOB_NAME, selector: specific(currentBuild.id)
                sh '''#!/bin/bash
                    find *Source -type f -iname '*.cab' -print0 |
                    while read -d $'\0' -r file; do
                        cmp $file `basename $file`
                    done
                    '''
            }
        }

        cleanWs()
    }
}

node()
{
    parallel(
        "ubuntu-23.10-ppc64le": { do_build('ubuntu-23.10-ppc64le', true, true, true, true) },
        "ubuntu-22.04-x86_64": { do_build('ubuntu-22.04', false, false, false, false) },
        "freebsd-14-x86_64": { do_build('freebsd', true, false, false, false) },
    )
}
