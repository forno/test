import moment from 'moment';

const now = moment();
const startThisMonth = now.startOf('month');
console.log(now.toDate());
console.log(startThisMonth.toDate());
const diff = now.diff(startThisMonth);
console.log(diff);
const duration = moment.duration(diff);
console.log(duration.asMonths());
console.log(duration.as('month'));
