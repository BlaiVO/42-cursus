git filter-branch --env-filter '
if [[ "$GIT_COMMITTER_EMAIL" = *nuferron* ]]
then
    export GIT_COMMITTER_EMAIL="nuriaf207@gmail.com"
fi
if [[ "$GIT_AUTHOR_EMAIL" = *nuferron* ]]
then
    export GIT_AUTHOR_EMAIL="nuriaf207@gmail.com"
fi
' -- --all
git push --force
