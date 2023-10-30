Rem from ~/Desktop/joplin/packages/app-desktop/ run the following including the empty newline:

cd ~/Desktop/joplin/packages/app-desktop/gui/MainScreen/commands/
tsc moveToFolder.ts
cd ~/Desktop/joplin/
yarn install
cd ~/Desktop/joplin/packages/app-desktop/
yarn start

Rem to test the file create moveToFolder.test.ts and run the following from the same directory

cd ~/Desktop/joplin/packages/app-desktop/gui/MainScreen/commands/
tsc moveToFolder.ts
cd ~/Desktop/joplin/packages/app-desktop/
yarn test moveToFolder.test.ts

