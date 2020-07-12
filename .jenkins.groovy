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

def notify(status, description)
{
    githubNotify account: 'meklort',
        context: JOB_NAME,
        credentialsId: 'jenkins_status',
        description: description,
        gitApiUrl: '',
        repo: 'bcm5719-fw',
        sha: GIT_COMMIT,
        status: status,
        targetUrl: BUILD_URL
}

def build(nodeName)
{
    node(nodeName)
    {
        cleanWs()
        def URL = ''
        def REFSPEC = '+refs/heads/*:refs/remotes/origin/*'
        try {
            URL = GITHUB_REPO_GIT_URL
        }
        catch (exc)
        {
            URL = 'git://github.com/meklort/bcm5719-fw.git'
        }
        def HASH = ''
        try {
            HASH = GITHUB_BRANCH_HEAD_SHA
        }
        catch (exc)
        {
            try {
                HASH = GITHUB_PR_HEAD_SHA
                REFSPEC = '+refs/pull/*:refs/remotes/origin/pr/*'
            }
            catch (exc2)
            {
                HASH = '**'
            }
        }
        stage('checkout')
        {
            checkout(
                [$class: 'GitSCM', branches: [[name: HASH]],
                                browser: [$class: 'GithubWeb',
                                repoUrl: 'https://github.com/meklort/bcm5719-fw/'],
                                doGenerateSubmoduleConfigurations: false,
                                extensions: [
                                    [$class: 'SubmoduleOption',
                                            disableSubmodules: false,
                                            parentCredentials: false,
                                            recursiveSubmodules: true,
                                            reference: '',
                                            trackingSubmodules: false]],
                                submoduleCfg: [],
                                userRemoteConfigs: [[
                                    url: URL,
                                    refspec: REFSPEC
                                ]]
            ])
        }

        stage('build')
        {
            sh './build.sh'
            dir('build')
            {
                archiveArtifacts artifacts: '*.zip', fingerprint: true
                archiveArtifacts artifacts: '*.tar.gz', fingerprint: true
            }
        }

        cleanWs()
    }
}

try
{
    notify('PENDING', 'Build Pending ')
    parallel(
        "fedora": { build('master') },
        "ubuntu-18.04": { build('ubuntu-18.04') },
    )
}
catch(e)
{
    currentBuild.result = 'FAILURE'
    throw e
}
finally
{
    def currentResult = currentBuild.result ?: 'SUCCESS'
    if(currentResult == 'SUCCESS')
    {
        notify('SUCCESS', 'Build Passed ')
    }
    else
    {
        notify('FAILURE', 'Build Failed ')
    }
}
