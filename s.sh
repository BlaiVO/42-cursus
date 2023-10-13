git filter-branch --env-filter '
if [[ "$GIT_COMMITTER_EMAIL" = *blvilarn* ]]
then
    export GIT_COMMITTER_EMAIL="blaivilarnauolid@gmail.com"
fi
if [[ "$GIT_AUTHOR_EMAIL" = *blvilarn* ]]
then
    export GIT_AUTHOR_EMAIL="blvilarnauolid@gmail.com"
fi
' -- --all
git push --force
